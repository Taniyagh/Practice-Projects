// JavaScript source code
window.onload=function(){
	const btn=document.getElementById('btn')
	const container=document.getElementById('container')
	btn.addEventListener('click',function(){
		createNotification()

	})
	
	function createNotification(){
		const Notf=document.createElement('div')
		Notf.classList.add('Notif')
		Notf.innerHTML='This is a notification!'
		container.appendChild(Notf)
		setTimeout(function(){container.removeChild(Notf)},3000)
	}
}