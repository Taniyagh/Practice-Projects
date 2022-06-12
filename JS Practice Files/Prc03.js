// JavaScript source code
function Validate(){
	/*const username=document.getElementById('username').value;
	const pattern=/USER/i;

	if(pattern.test(username)){
		alert('valid username')
	}else{
		alert('invalid username')
	}*/
	const phone=document.getElementById('phone').value
	const pattern=/^[0]{2}[9][8][0-9]{10}$/

	if(pattern.test(phone)){
		alert('valid phone number')
	}else{
		alert('invalid phone number')
	}
}