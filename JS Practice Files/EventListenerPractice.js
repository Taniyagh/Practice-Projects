// JavaScript source code
window.onload= function(){
	/*
	const userList=document.querySelectorAll('.name-list li')
	console.log("userList")
	for (user of userList){
		user.addEventListener('click',function(){
		console.log(this)
		this.style.color="red"
		}
		)
	}
	*/
	let userList=document.querySelector('.name-list')
	let userInput=document.querySelector('.list-input')
	let btn=document.querySelector('.addListButton')
	btn.addEventListener('click',function(){
		const newUser=document.createElement('li');
		const name=document.createTextNode(userInput.value);
		newUser.appendChild(name);
		userList.appendChild(newUser);
		userInput.value='';

		//this.style.color="yellow"	
	})
}