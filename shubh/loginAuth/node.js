

const express = require('express');
const bodyParser = require('body-parser');
const url = require('url');
const http = require('http');
const app = express();
const { readFile } = require('fs').promises;
const fs = require('fs');
const { spawn } = require('child_process');


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
    //console.log(c);
    fs.writeFile('authCode.txt', codeA, (err) => {
        if (err) throw err;
        console.log('Data written to file');
      });
    response.send( await readFile('./callback.html', 'utf8') );

});

app.post('/playlists', (req, res) => {
    
    

    const child = spawn('./request1.cpp');
    
    child.stdout.on('data', (data) => {
      console.log(`C++ output: ${data}`);
    });
    
    child.stderr.on('data', (data) => {
      console.error(`C++ error: ${data}`);
    });
    
    child.on('close', (code) => {
      console.log(`C++ process exited with code ${code}`);
    });
});
app.listen(process.env.PORT || 8080, () => console.log(`App available on http://localhost:8080`));
