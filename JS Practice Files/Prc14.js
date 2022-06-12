// JavaScript source code
window.onload=function(){
	const btn=document.getElementById('btn');
	const menu=document.getElementById('nav');
	btn.addEventListener('click',function(){
	 menu.classList.toggle('active')
	 btn.classList.toggle('active')
	})
	
}