document.addEventListener('DOMContentLoaded', () => {
    // Fetch JSON and populate the articles
    fetch('titoli.json')
        .then(response => response.json())
        .then(data => {
            const section = document.getElementById('articles-section');
            
            data.forEach(article => {
                const articleElement = document.createElement('article');
                articleElement.innerHTML = `<h3>${article.titolo}</h3><p>${article.contenuto}</p>`;
                section.appendChild(articleElement);
            });
        });

    // Toggle menu visibility and color change
    const nav_menu = document.querySelector('header p');
    nav_menu.addEventListener('click', () => {
        if (window.innerWidth < 1000) {
            const menu = document.getElementById('menu');
            menu.classList.toggle('hidden');
            nav_menu.style.cursor = "pointer"
            nav_menu.style.color = nav_menu.style.color === 'red' ? 'black' : 'red';
        }
    });

    // Shuffle articles on title click
    const articlesTitle = document.querySelector('#articles-section h2');
    articlesTitle.addEventListener('click', () => {
        const articles = Array.from(document.querySelectorAll('article'));
        shuffleArray(articles);
        const section = document.getElementById('articles-section');
        articles.forEach(article => section.appendChild(article));
    });

    function shuffleArray(array) {
        array.sort(() => Math.random() - 0.5);
    }
});

// CSS class to hide elements
const style = document.createElement('style');
style.innerHTML = `
    .hidden {
        display: none;
    }
`;
document.head.appendChild(style);
