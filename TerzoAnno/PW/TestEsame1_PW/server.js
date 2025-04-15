// const express = require("express");
// const fs = require("fs");
// const morgan = require("morgan");
// const app = express();

// app.use(morgan("dev"));
// app.use(express.json()); // for parsing application/json

// const prod_list = JSON.parse(fs.readFileSync(__dirname + "/data/frasi.json"));

// app.get("/", (req, res) => {
//   res.sendFile(__dirname + "/index.html");

// });
// app.get("/style.css", (req, res) => {
//     res.sendFile(__dirname + "/style.css");
//   });
//   app.get("/script.js", (req, res) => {
//     res.sendFile(__dirname + "/script.js");
//   });
// app.get("/citations", (req, res) => {
//   const ret_json = {
//     status: "success",
//     data: prod_list,
//   };
//   res.json(ret_json);
// });

// app.get("/citations/:ID", (req, res) => {
//   const id = req.params.ID;
//   const data = prod_list.find((el) => el.ID == id);
//   if (!data) {
//     return res.status(404).json({
//       status: "Error",
//       message: "Product not found",
//     }); //formato errore JSend
//   }
//   res.json({
//     status: "success",
//     data: data,
//   });
// });

// app.listen(3000, () => {
//   console.log("Server running on http://localhost:3000");
// });

const express = require("express");
const morgan = require("morgan");
const fs = require("fs");
const path = require("path");
const app = express();
const cors = require("cors");

app.use(morgan("dev"));
app.use(express.json()); // for parsing application/json

app.use(cors())
// Leggi il file JSON contenente le citazioni
let citations;
try {
  const data = fs.readFileSync(__dirname + "/data/frasi.json", "utf8");
  citations = { citations: JSON.parse(data) };
  if (!Array.isArray(citations.citations)) {
    throw new Error("frasi.json does not contain an array");
  }
} catch (error) {
  console.error("Error reading or parsing citations.json:", error.message);
  process.exit(1);
}

// Usa morgan per il logging delle richieste
app.use(morgan("dev"));

// Serve static files from the "public" directory
app.use(express.static(path.join(__dirname, "public")));

// Endpoint per ottenere tutte le citazioni
app.get("/citations", (req, res) => {
  const ret_json = {
    status: "success",
    data: citations,
  };
  res.json(ret_json);
});

// Endpoint per ottenere una citazione per ID
app.get("/citations/:ID", (req, res) => {
  const id = parseInt(req.params.ID);
  const citation = citations.citations.find((c) => c.ID === id);
  if (citation) {
    res.json(citation);
  } else {
    res.status(404).json({ status: "fail", message: "Frase not found" });
  }
});

// Avvia il server
app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
