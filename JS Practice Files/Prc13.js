// JavaScript source code
window.onload= function(){
	function createHeart(){
		const heart=document.createElement('div');
		heart.style.left=Math.random()*100+'vw';
		heart.style.animationDuration=Math.random()*2+'s'
		heart.classList.add('heart');
		heart.innerText='❤️';
		document.body.appendChild(heart);
		setTimeout(function(){heart.remove()},5000)
	}
	setInterval(createHeart,300)
}