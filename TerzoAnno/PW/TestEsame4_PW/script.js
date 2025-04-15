document.addEventListener('DOMContentLoaded', () => {
    fetch('colori.json')
        .then(response => response.json())
        .then(jsonData => {
            const mainContent = document.getElementById('main-content');
            const sectionWrapper = document.createElement('div');
            sectionWrapper.classList.add('section-wrapper');
            mainContent.appendChild(sectionWrapper);

            jsonData.forEach(item => {
                const section = document.createElement('section');
                section.style.backgroundColor = item.colore;

                const h3 = document.createElement('h3');
                h3.textContent = item.titolo;

                section.appendChild(h3);
                sectionWrapper.appendChild(section);
            });
        })
        .catch(error => {
            console.error('Error fetching the JSON data:', error);
        });

    const overlay = document.getElementById('overlay');
    const closeOverlay = document.getElementById('close-overlay');

    closeOverlay.addEventListener('click', () => {
        overlay.style.display = 'none';
    });

    // To show the overlay for demonstration, uncomment the line below
    overlay.style.display = 'flex';
});
