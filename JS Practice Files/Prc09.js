// JavaScript source code
window.onload= function()
{
	const btn=document.getElementById('btn');
	btn.addEventListener('click',function(){
		document.body.style.background=randBG()
	})
	setInterval(randBG,1000);

	function randBG(){
		//return `rgb(${Math.floor(Math.random()*255)},${Math.floor(Math.random()*255)},${Math.floor(Math.random()*255)})`
		document.body.style.background=`hsl(${Math.floor(Math.random()*360)},100%,50%)`;
	}
}