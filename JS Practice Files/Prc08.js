// JavaScript source code
const text="I am studing front-end development. ";
let index=0;
function autoWrite(){
	document.body.innerText=text.slice(0,index);
	index++;
	if(index>text.length-1){
		index=0
	}
}
setInterval(autoWrite,100)