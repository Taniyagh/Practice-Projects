// JavaScript source code

function textInputHandler(){
	const username=document.getElementById('username').value
	const password=document.getElementById('password').value
}
function radioInputHandler(){
	const banana=document.getElementById('banana')
	const apple=document.getElementById('apple')
	if (banana.checked){
		console.log('the selected fruit is: '+banana.value)
	}else{
		console.log('the selected fruit is: '+apple.value)
	}
	}
function selectOptionHandler(){
	const selectBox=document.getElementById('selectbox')
	console.log(selectbox.options[selectbox.selectedIndex].value)
}
window.onload= function(){
	const form= document.forms.Myform
	console.log(form.name.value)
	console.log(form.color.value)
}