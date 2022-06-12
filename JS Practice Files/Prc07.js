// JavaScript source code
window.onload =function(){
	const container=document.getElementById('container')
	const img=document.querySelector('img')

	container.addEventListener('mouseover',function(e){
		const X=e.clientX-e.target.offsetLeft;
		const Y=e.clientY-e.target.offsetTop;
		
		console.log(X,Y);
		img.style.transformOrigin=`${X}px ${Y}px`;
		img.style.transform='scale(1.2)';
	})
	container.addEventListener('mouseleave',function(e){
		img.style.transformOrigin=`center center`;
		img.style.transform='scale(1)';
	})

}