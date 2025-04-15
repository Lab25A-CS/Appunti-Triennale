document.addEventListener("DOMContentLoaded", function () {
  fetch("immagini.json")
    .then((response) => response.json())
    .then((data) => {
      const gallery = document.querySelector(".gallery-container");
      data.forEach((el) => {
        const img = document.createElement("img");
        img.src = el.src;
        img.alt = el.alt;
        img.addEventListener("load", () => (img.style.opacity = 1));
        img.addEventListener("click", () => showOverlay(img.src));
        gallery.appendChild(img);
      });
    })
    .catch((error) => console.log("Errore nel recupero dei dati JSON", error));

  const overlay = document.getElementById("overlay");
  const overlayImage = document.getElementById("OverlayImage");
  const closeOverlay = document.getElementById("closeOverlay");

  closeOverlay.addEventListener(
    "click",
    () => (overlay.style.display = "none")
  );

  
});
function showOverlay(src) {
    overlayImage.src = src;
    overlay.style.display = "flex";
  }

//creazione di un carosello

// let currentImageIndex = 0;
// setInterval(() => {
//     const images = document.querySelectorAll('.gallery-container img');
//     if (images.length > 0) {
//         currentImageIndex = (currentImageIndex + 1) % images.length;
//         showOverlay(images[currentImageIndex].src);
//     }
// }, 1000);