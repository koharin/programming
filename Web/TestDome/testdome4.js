function getMessageText() {
  return $('#message').text();
}

document.body.innerHTML = '<div id="message">The message</div>';
console.log(getMessageText());