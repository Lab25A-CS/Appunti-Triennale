import java.util.ArrayList;

public class JAVAProducerConsumerWithMonitor {
    static final int N = 10; // Dimensione del buffer

    static final int consumerSleepMilliSec = 200;
    static final int producerSleepMilliSec = 200;

    static Producer p = new Producer(); // Istanza del thread produttore
    static Consumer c = new Consumer(); // Istanza del thread consumatore

    static OurMonitor mon = new OurMonitor(); // Istanza del monitor

    // Classe produttore
    static class Producer extends Thread {
        public void run() {
            int item;
            while (true) { // Ciclo produttore
                // Produce
                item = produceItem(); // NOT SAFE, not important
                // Insert
                mon.insert(item); // SAFE
                // Sleep
                try {
                    Thread.sleep((int) (Math.random() * producerSleepMilliSec));
                } catch (Exception e) {
                    // catching the exception
                    System.err.println(e);
                }
            }
        }

        private int produceItem() {
            // Implementazione della produzione di un elemento
            // Questa parte deve essere implementata in base alle necessità
            return (int) (Math.random() * 100);
        }
    }

    // Classe consumatore
    static class Consumer extends Thread {
        public void run() {
            while (true) { // Ciclo consumatore
                mon.remove();
                try {
                    Thread.sleep((int) (Math.random() * consumerSleepMilliSec));
                } catch (Exception e) {
                    // catching the exception
                    System.err.println(e);
                }
            }
        }

    }

    // Classe che rappresenta il monitor
    static class OurMonitor {
        private ArrayList<Integer> buffer = new ArrayList<Integer>();

        public synchronized String getBufferStr() {
            String res = "";
            for (int i = 0; i < buffer.size(); i++) {
                res += buffer.get(i) + " ";
            }
            return res.trim();
        }

        public synchronized void insert(int val) {
            while (buffer.size() == N) // Se il buffer è pieno, attendi
                goToSleep();

            System.out.println("\nProdotto: " + val);
            buffer.add(val);
            System.out.println("Buffer\t" + mon.getBufferStr());

            if (buffer.size() == 1)
                notify();
        }

        public synchronized int remove() {
            while (buffer.size() == 0) // Se il buffer è vuoto, attendi
                goToSleep();

            int val = buffer.get(0);
            // Implementazione del consumo di un elemento
            System.out.println("\nConsumato: " + val);
            buffer.remove(0);
            System.out.println("Buffer\t" + mon.getBufferStr());

            if (buffer.size() == N - 1)
                notify();
            return val;
        }

        private void goToSleep() {
            try {
                wait();
            } catch (InterruptedException e) {
                // Gestione dell'eccezione
                System.err.println(e);
            }
        }
    }

    public static void main(String args[]) {
        p.start(); // Avvio del thread produttore
        c.start(); // Avvio del thread consumatore
    }
}