// JavaScript source code
window.onload= function(){
	const popup=document.querySelector('.notification')
	const open= document.getElementById('open')
	const close=document.getElementById('close')
	open.addEventListener('click',function(){
		document.body.style.background='rgba(0,0,0,0.5)';
		open.style.display="none";
		popup.classList.add('active')
	})
	close.addEventListener('click',function(){
		document.body.style.background='#fff';
		open.style.display="block";
		popup.classList.remove('active')
	})
}