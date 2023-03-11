

const express = require('express');
const bodyParser = require('body-parser');
const url = require('url');
const http = require('http');
const app = express();
const { readFile } = require('fs').promises;
const fs = require('fs');
const { exec } = require('child_process');
const path = require('path');
var theAuthCode = null;


app.use(express.urlencoded({ extended: true }));

http.createServer((req, res) => {
    const query = url.parse(req.url, true).query;
    const code = query.code;
  
    fs.writeFile('auth_code.txt', code, (err) => {
      if (err) throw err;
      console.log('Authentication code saved to auth_code.txt');
    });
  
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.write('Authentication code saved!');
    res.end();
  });

app.get('/', async (request, response) => {

    response.send( await readFile('./initButton.html', 'utf8') );

});

app.get('/callback', async (request, response) => {


    console.log(request.url);
    const codeA = url.parse(request.url, true).query.code;
    theAuthCode = codeA;
    //console.log(c);
    fs.writeFile('authCode.txt', codeA, (err) => {
        if (err) throw err;
        console.log('Data written to file');
      });
    response.send( await readFile('./callback.html', 'utf8') );

});

app.post('/playlists', (req, res) => {

  //go to backend code dir
  const directoryPath = path.resolve('../backend_getPlaylists');
  process.chdir(directoryPath);

  

exec('make', (error, stdout, stderr) => {
  if (error) {
    console.error(`Error executing make command: ${error}`);
    return;
  }
  console.log(`make command output: ${stdout}`);
}); 
 });
app.listen(process.env.PORT || 8080, () => console.log(`App available on http://localhost:8080`));
