// JavaScript source code
window.onload= function(){
	const imgs=document.getElementById("imgs");
	const img= document.querySelectorAll('#imgs img');
	let idx=0;

	function run(){
		idx++;
		if (idx>img.length-1)
			idx=0;
		imgs.style.transform=`translateX(${-500*idx}px)`
	}	
	setInterval(run,3000)

}
