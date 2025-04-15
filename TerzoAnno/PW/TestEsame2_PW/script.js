let jsonData = [];
        async function load(){
            const response = await fetch("colori.json");
            jsonData = await response.json();
            jsonData.forEach(item => console.log(item));
        }
        load()
        function drawSquare(){
            const mainContainer = document.getElementById("main-container");
            mainContainer.innerHTML = ''; /*per pulire i quadrati precedenti*/
            jsonData.forEach(item => {
                const square = document.createElement("div");
                square.style.width = "10%";
                square.style.height = "10%";
                square.style.backgroundColor = item.colore;

                const left = Math.min(item.pos_orizz,90) //per evitare overflow
                const top = Math.min(item.pos_vert,90)
                square.style.left = left + "%";
                square.style.top = top + "%";
                square.style.position = "absolute";
                square.addEventListener('click',(e)=>e.target.remove());
                mainContainer.appendChild(square);
            });
        }