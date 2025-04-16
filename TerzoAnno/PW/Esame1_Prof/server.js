const express = require("express");
const fs = require("fs");
const cors = require("cors");

const app = express();

app.use(cors());

const cit_list = JSON.parse(fs.readFileSync("citations.json"));

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index.html");
});

app.get("/citations/", (req, res) => {
  const ret_json = {
    status: "success",
    data: cit_list,
  };
  res.json(ret_json);
});

app.get("/citations/:id", (req, res) => {
  const id = req.params.id;
  const cit = cit_list.find((el) => el.ID == id);
  if (!cit) {
    return res.status(404).json({
      status: "error",
      message: "cit not found",
    });
  }
  res.json({
    status: "success",
    data: cit,
  });
});

app.listen(3000, () => {
  console.log("Server is running on http://localhost:3000");
});
