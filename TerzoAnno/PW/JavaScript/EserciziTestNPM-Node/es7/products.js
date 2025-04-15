const express = require("express");
const router = express.Router();

router.get("/", (req, res) => {
  const ret_json = {
    status: "success",
    data: prod_list,
  };
  res.json(ret_json);
});

router.get("/:id", (req, res) => {
  const id = req.params.id;
  const product = prod_list.find((el) => el.id == id);
  if (!product) {
    return res.status(404).json({
      status: "error",
      message: "product not found",
    });
  }
  res.json({
    status: "success",
    data: product,
  });
});

router.delete("/:id", (req, res) => {
  const id = req.params.id;
  const index = prod_list.findIndex((el) => el.id == id);
  if (index == -1) {
    return res.status(404).json({
      status: "error",
      message: "product not found",
    });
  }
  prod_list.splice(index, 1);
  res.status(204).json({
    status: "success",
  });
});

router.post("/", (req, res) => {
  console.log(req.body);

  // Verifica che il body della richiesta contenga i campi obbligatori
  if (!req.body.nome || !req.body.cantina) {
    return res.status(422).json({
      status: "error",
      message: "nome and cantina are required",
    });
  }
  // Creare un id
  const id = prod_list[prod_list.length - 1].id + 1;
  req.body.id = id;

  // Aggiungere il nuovo prodotto alla lista
  prod_list.push(req.body);
  res.status(201).json({
    status: "success",
    data: req.body,
  });
});

module.export = router;
