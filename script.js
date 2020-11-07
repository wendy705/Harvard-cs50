/*Handle requests from background.html*/
function handleRequest(
	//The object data with the request params
	request, 
	//These last two ones isn't important for this example, if you want know more about it visit: http://code.google.com/chrome/extensions/messaging.html
	sender, sendResponse
	) {
	if (request.callFunction == "toggleSidebar")
		toggleSidebar();
}
chrome.extension.onRequest.addListener(handleRequest);

/*Small function wich create a sidebar(just to illustrate my point)*/
var sidebarOpen = false;
function toggleSidebar() {
	if(sidebarOpen) {
		var el = document.getElementById('mySidebar');
		el.parentNode.removeChild(el);
		sidebarOpen = false;
	}
	else {
		var iframe = document.createElement('iframe');
		iframe.id = "mySidebar";
		iframe.style.background = "green";
		iframe.style.height = "100%";
		iframe.style.width = "25%";
		iframe.style.position = "fixed";
		iframe.style.top = "0px";
		iframe.style.left = "0px";
		iframe.style.zIndex = "9000000000000000000";
		iframe.frameBorder = "none"; 
		iframe.src = chrome.extension.getURL("index.html");
		document.body.appendChild(iframe);
		sidebarOpen = true;
	}
}