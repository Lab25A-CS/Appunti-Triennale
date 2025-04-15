fetch("esami.json")
  .then((response) => response.json())
  .then((data) => {
    const esami = data.esami;
    const tableBody = document.querySelector("#esami tbody");

    esami.forEach((esame) => {
      const row = document.createElement("tr");

      const idCell = document.createElement("td");
      idCell.textContent = esame.id;
      row.appendChild(idCell);

      const nomeCell = document.createElement("td");
      nomeCell.textContent = esame.nome;
      row.appendChild(nomeCell);

      const dataCell = document.createElement("td");
      dataCell.textContent = esame.data;
      row.appendChild(dataCell);

      const votoCell = document.createElement("td");
      votoCell.textContent = esame.voto;
      row.appendChild(votoCell);

      tableBody.appendChild(row);
    });
  })
  .catch((error) => console.log("Errore nel recupero del file JSON", error));
