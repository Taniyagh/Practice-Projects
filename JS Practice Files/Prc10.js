// JavaScript source code
window.onload= function(){
	const toggle=document.getElementById('toggle')
	toggle.addEventListener('change',function(e){
		document.body.classList.toggle('dark',e.target.checked)
	})
}