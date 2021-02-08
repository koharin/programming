//CLEAR
function setup() {
    var els = document.getElementsByClassName("remove");
    console.log(els);
    for (var i = 0; i < els.length; i++) {
        els[i].addEventListener('click', function () {
            this.parentNode.remove(); //e.target.closest('div.image').remove();
        });
    }
}

// Example case. 
document.body.innerHTML = `
<div class="image">
<img src="https://goo.gl/kjzfbE" alt="First">
<button class="remove">X</button>
</div>
<div class="image">
<img src="https://goo.gl/d2JncW" alt="Second">
<button class="remove">X</button>
</div>`;

setup();

document.getElementsByClassName("remove")[0].click();
console.log(document.body.innerHTML);