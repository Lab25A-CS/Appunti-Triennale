const express = require("express");
const cors = require("cors");
const morgan = require("morgan");
const path = require("path");

const app = express();
app.use(morgan("dev"));
app.use(express.json());
app.use(cors());

app.use(express.static(path.join(__dirname, "public")));

app.get("/articoli", (req, res) => {
  res.sendFile(__dirname + "/data/articoli.json");
});

app.get("/articoli/:title", (req, res) => {
  const art_title = req.params.title;
  const articoli = require("./data/articoli.json");
  const articolo = articoli.find((el) => el.titolo === art_title);

  if (articolo) {
    res.json(articolo);
    console.log("Articolo trovato:",articolo)
  } else {
    res.status(404).json({ status: "fail", message: "Articolo non trovato" });
  }
});

app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
