package GestioneAuto;


/*
Ogni componente per l’auto (da ora in poi prodotto) è descritto tramite un identificativo, un’etichetta di
riferimento, un costo di produzione, un prezzo agli acquirenti e la lista dei suoi componenti (intesi come
subcomponenti del componente per l’auto, ossia del prodotto) e da dove questi provengono. Il manager della
fabbrica vuole mantenere un archivio dei componenti di ogni prodotto indicando il loro nome, il paese di
provenienza, i tempi di ordinazione e il costo. Ogni prodotto è descritto non solo dai suoi componenti, ma
dal loro numero e dal tempo totale stimato per l’ordine dei componenti (che è dato dal tempo di ordine
massimo tra quelli dei componenti necessari), oltre ad un tempo necessario per la realizzazione del prodotto
finito. Sia il tempo per l’ordine che il tempo di realizzazione sono esprimibili, per semplicità, in giorni (o
frazioni di essi). Il tempo necessario all’assemblaggio, moltiplicato per un costo giornaliero di fabbricazione
unico della fabbrica (ma deve poter essere regolato) fornisce il costo di realizzazione di ogni singolo prodotto.
 */


import java.util.ArrayList;

public class Prodotto {
    public int identificativo;
    public  String etichetta;
    private double costoProduzioneAlGiorno;
    private double costo;
    private double tassoDiVendita;
    private ArrayList<Componente> listaComponentiPrivati;
    public ArrayList<Componente> listaComponentiPublici;
    private int numeroComponenti;
    private int orePerOrdinazione;
    private int orePerRealizzazione;
    private double costoComponenti;
    private String provenienza;


    Prodotto(int identificativo, String etichetta, Double costoProduzioneAlGiorno, String provenienza, double tassoDiVendita){
        this.identificativo = identificativo;
        this.etichetta = etichetta;
        this.costoProduzioneAlGiorno = costoProduzioneAlGiorno;
        this.listaComponentiPrivati = new ArrayList<Componente>();
        this.listaComponentiPublici = new ArrayList<Componente>();
        this.orePerOrdinazione = 0;
        this.orePerRealizzazione = 0;
        this.costoComponenti = 0;
        this.costo = 0;
        this.tassoDiVendita = tassoDiVendita;
        this.provenienza = provenienza;
    }

    void AggiuntaComponente(Componente oggetto){
        listaComponentiPublici.add(oggetto);
        if (orePerOrdinazione <= oggetto.getTempoDiOrdinazione()){
            orePerOrdinazione = oggetto.getTempoDiOrdinazione();
            orePerRealizzazione = orePerOrdinazione + 24;
        }
        numeroComponenti++;
        costoComponenti += oggetto.getCostoComponente();
        costo = CalcoloCostoDiVendita();
    }

    void AggiuntaComponente(Componente oggetto, boolean privato){
        listaComponentiPrivati.add(oggetto);
        if (orePerOrdinazione <= oggetto.getTempoDiOrdinazione()){
            orePerOrdinazione = oggetto.getTempoDiOrdinazione();
            orePerRealizzazione = orePerOrdinazione + 24;
        }
        numeroComponenti++;
        costoComponenti += oggetto.getCostoComponente();
        costo = CalcoloCostoDiVendita();
    }


    double CalcoloCostoRealizzazione(){
        return costoProduzioneAlGiorno*(orePerRealizzazione/24);
    }

    double CalcoloCostoRealizzazione(double costoAlternativo){
        return costoAlternativo*(orePerRealizzazione/24);
    }

    double CalcoloCostoDiVendita(){
        double costoRealizzazione = CalcoloCostoRealizzazione();
        return (costoRealizzazione + costoComponenti) * tassoDiVendita;
    }

    @Override
    public String toString() {
        return "Prodotto{" +
                " etichetta :" + etichetta +
                ", listaComponentiPublici : " + listaComponentiPublici +
                ", prezzo :" + costo +
                '}';
    }

    public double getCosto() {
        return costo;
    }
}
