const express = require("express");
const fs = require("fs");
const morgan = require("morgan");
const app = express();

const product = require("./products");

app.use(morgan("dev"));
app.use(express.json()); // for parsing application/json

const prod_list = JSON.parse(fs.readFileSync("data/products.json"));

app.get("/index.html", (req, res) => {
  res.sendFile(__dirname + "/index.html");
});

app.use("/api/v1/products", product);

app.listen(3000, () => {
  console.log("Server running on port 3000");
});
