const express = require("express");
const morgan = require("morgan");
const fs = require("fs");
const path = require("path");
const app = express();
const cors = require("cors");

app.use(morgan("dev"));
app.use(express.json()); // for parsing application/json

app.use(cors());

// Serve static files from the "public" directory
app.use(express.static(path.join(__dirname, "public")));

const persone = JSON.parse(fs.readFileSync(__dirname + "/dati.json"))

app.get("/persone", (req, res) => {
  const ret_json = {
    status: "success",
    data: persone,
  };
  res.json(ret_json);
});

app.get("/persone/:id", (req, res) => {
    const id = req.params.id;
    const pers = persone.find((el) => el.id == id);
    if (!pers) {
      return res.status(404).json({
        status: "error",
        message: "Persona not found",
      });
    }
    res.json({
      status: "success",
      data: pers,
    });
  });

// Avvia il server
app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
