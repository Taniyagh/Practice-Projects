// JavaScript source code
function Validate(){
	const username=document.getElementById('username')
	const password=document.getElementById('password')
	const message=document.getElementById('message')
	const usError=document.getElementById('usError')
	/*if (username.value.trim()==='' || password.value.trim()===''){
		message.innerHTML="You must put all inputs."
		return false
	}else{*/
	if(username.value.trim()===''){
		username.style.border="red 2px solid";
		usError.style.visibility="visible";
		message.innerHTML="You must enter a valid username";
		return false		
	}else if (password.value.trim()===''){
		password.style.border="red 2px solid";
		passError.style.visibility="visible";
		username.style.border="1px solid black";
		usError.style.visibility="hidden";
		message.innerHTML="You must enter a valid password";
		return false
	}else if(password.value.trim().length<=5){
		password.style.border="red 2px solid";
		passError.style.visibility="visible";
		message.innerHTML="Your password is too short";
		return false
	}else{
		message.innerHTML=""	
		return true	
	}
}