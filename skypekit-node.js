var fs = require('fs');

var skypekit = require('./build/Debug/skypekit');

var skype = new skypekit.Skype();

var login = process.argv[2];
var password = process.argv[3];

skype.setKey(fs.readFileSync('skypekit.pem'));
skype.setLogin(login);
skype.setPassword(password);

skype.login();

setInterval(function() {}, 100)