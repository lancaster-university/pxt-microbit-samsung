var express = require('express'),
  app = express(),
  port = 8000,
  bodyParser = require('body-parser');

app.use(express.static("../static"))

console.log("pxt hosted on: ", 8001)
app.listen(8001);