const express = require("express");
const fs = require("fs");
const morgan = require("morgan");
const app = express();

app.use(morgan("dev"));
app.use(express.json()); // for parsing application/json

const prod_list = JSON.parse(fs.readFileSync(__dirname+"/data/products.json"));

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index.html");
});

app.get("/api/v1/products/", (req, res) => {
  const ret_json = {
    status: "success",
    data: prod_list,
  };
  res.json(ret_json);
});

app.get("/api/v1/products/:id", (req, res) => {
  const id = req.params.id;
  const product = prod_list.find((el) => el.id == id);
  console.log(product);
  if (!product) {
    return res.status(404).json({
      status: "Error",
      message: "Product not found",
    });
  }
  res.json({
    status: "success",
    data: product,
  });
});

app.delete("/api/v1/products/:id", (req, res) => {
  const id = req.params.id;
  const index = prod_list.findIndex((el) => el.id == id);
  if (index == -1) {
    return res.status(404).json({
      status: "Error",
      message: "Product not found",
    });
  }
  prod_list.splice(index, 1);
  res.status(204).json({
    status: "Success",
    message: "Product deleted successfully",
  });
});

app.post("/api/v1/products/", (req, res) => {
  console.log(req.body);

  // Verifica che il body della richiesta contenta i campi obbligatori
  if (!req.body.nome || !req.body.cantina) {
    return res.status(422).json({
      status: "Error",
      message: "Missing name or cantina",
    });
  }

  //Creare un ID
  const id = prod_list[prod_list.length - 1].id + 1;
  req.body.id = id;

  //Aggiungere il nuovo prodotto alla lista

  prod_list.push(req.body);
  res.status(201).json({
    status: "Success",
    message: "Product added successfully",
    data: req.body,
  });
});

app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
