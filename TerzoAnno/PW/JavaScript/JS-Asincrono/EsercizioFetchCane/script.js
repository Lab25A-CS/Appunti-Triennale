function caricaImmagine() {
    fetch('https://dog.ceo/api/breeds/image/random')
    .then(response => response.json())
    .then(data => {
        const imageUrl = data.message;
        const dogImage = document.createElement('img');
        dogImage.src = imageUrl;
        dogImage.alt = 'Immagine di Cane';
        document.getElementById('dog-image').innerHTML = '';
        document.getElementById('dog-image').appendChild(dogImage);
	console.log("Ho fetchato le API correttamente")
    })
    .catch(error => console.error('Si è verificato un errore:', error));
}


