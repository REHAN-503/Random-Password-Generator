const express = require('express');
const { execFile } = require('child_process');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 4000;
const BINARY = path.join(__dirname, 'bin', 'passgen');

app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

app.get('/api/generate', (req, res) => {
  const length    = Math.min(Math.max(parseInt(req.query.length)    || 16, 4), 128);
  const useUpper  = req.query.upper   === 'false' ? 0 : 1;
  const useDigits = req.query.digits  === 'false' ? 0 : 1;
  const useSyms   = req.query.symbols === 'false' ? 0 : 1;
  const count     = Math.min(Math.max(parseInt(req.query.count) || 1, 1), 20);

  execFile(BINARY, [length, useUpper, useDigits, useSyms, count], (err, stdout, stderr) => {
    if (err) {
      console.error('passgen error:', stderr);
      return res.status(500).json({ error: 'Generation failed' });
    }
    const passwords = stdout.trim().split('\n').filter(Boolean);
    res.json({ passwords });
  });
});

app.listen(PORT, () => {
  console.log(`🔐 PassGen running on http://localhost:${PORT}`);
});
