var fs = require('fs');
var util = require('util');
var events = require('events');

var skypekit = require('./build/Debug/skypekit');
util.inherits(skypekit.Skype, events.EventEmitter);

var skype = new skypekit.Skype();

var login = process.argv[2];
var password = process.argv[3];

skype.setKey(fs.readFileSync('skypekit.pem'));
skype.setLogin(login);
skype.setPassword(password);

skype.on('login', function() {
	console.log('Yay! We are logged in now!')
})

skype.login();

setInterval(function() {
	skype.toString();
}, 10000)