(function(window, undefined){
	
	window.AscCrypto = window.AscCrypto || {};
	if (window.AscCrypto.CryptoWorker)
		return;
	
	window.AscCrypto.CryptoWorker = {};
	window.AscCrypto.CryptoWorker.isUseOnePasswordOnAllVersions = false;
	window.AscCrypto.CryptoWorker.TmpPassword = "";
	window.AscCrypto.CryptoWorker.User = null;	
	
	// read user info
	window.AscCrypto.CryptoWorker.init = function(users, password)
	{
		this.User = window.AscDesktopEditor.CryptoCloud_GetUserInfo();
	};	
	// create from passwords
	window.AscCrypto.CryptoWorker.generateDocInfo = function(users, password)
	{
		var result = "";
		for (var i = 0, len = users.length; i < len; i++)
		{
			if (users[i].publicKey)
			{
				result += (users[i].userId + "\n");
				result += (window.AscDesktopEditor.CryproRSA_EncryptPublic(users[i].publicKey, password) + "\n\n");
			}				
		}
		return result;
	};
	// decrypt password from docinfo
	window.AscCrypto.CryptoWorker.readPassword = function(docinfo)
	{
		if (docinfo == null)
			docinfo = "";
		
		var user = this.User[2];
		var index = docinfo.indexOf(user);
		
		if (-1 == index)
			return "";
		
		var delimeter = "<!--break-->";
		var start = docinfo.indexOf(delimeter, index);
		if (-1 == index)
			return "";
		
		var end = docinfo.indexOf(delimeter, start + 1);
		if (-1 == end)
			return "";
		
		var encPassword = docinfo.substring(start + delimeter.length, end);
		return window.AscDesktopEditor.CryproRSA_DecryptPrivate(this.User[0], encPassword);
	};	
	// генерация нового пароля
	window.AscCrypto.CryptoWorker.createPasswordNew = function() {
		function s4() {
			return Math.floor((1 + Math.random()) * 0x10000).toString(16).substring(1);
		}
		return s4() + s4() + '-' + s4() + '-' + s4() + '-' + s4() + '-' + s4() + s4() + s4();
	}
	// запрос на новый пароль
	window.AscCrypto.CryptoWorker.createPassword = function(oldPassword)
	{
		var password = oldPassword;
		if (null == password || "" == password || true !== this.isUseOnePasswordOnAllVersions)
			password = this.createPasswordNew();
		return password;
	};	
	window.AscCrypto.CryptoWorker.generatePassword = function(oldPassword)
	{
		this.TmpPassword = this.createPassword(oldPassword);
				
		window.AscDesktopEditor.cloudCryptoCommandMainFrame({ type: "getsharingkeys" }, function(obj){
			
			worker = window.AscCrypto.CryptoWorker;
			window.Asc.plugin.onSystemMessage({ 
				type : "generatePassword", 
				password : worker.TmpPassword, 
				docinfo : (obj.keys && obj.keys.length) ? worker.generateDocInfo(obj.keys, worker.TmpPassword) : ""
			});
			worker.TmpPassword = "";
			
		});
	};
	// шифрование изменений
	window.AscCrypto.CryptoWorker.cryptInit = function(password)
	{
		window.AscDesktopEditor.CryptoAES_Init(password);
	};
	window.AscCrypto.CryptoWorker.encrypt = function(data)
	{
		return window.AscDesktopEditor.CryptoAES_Encrypt(data);
	};
	window.AscCrypto.CryptoWorker.decrypt = function(data)
	{
		return window.AscDesktopEditor.CryptoAES_Decrypt(data);
	};
	
	// init
	window.AscCrypto.CryptoWorker.init();
	
})(window, undefined);
