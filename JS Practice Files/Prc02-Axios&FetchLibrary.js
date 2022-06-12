// JavaScript source code
var text="{
	"Employee":[
	{"firstName":"John", "lastName":"Doe"},
	{"firstName":"Anna", "lastName":"Smith"},
	{"firstName":"Peter", "lastName":"Joes"}]"}"

	let obj=JSON.parse(text);

window.onload=function(){
	const option={
		url:'https://jsonplaceholder.ir/users',
		method:'GET',
		headers:{
			'Accept':'application/json',
			'content-Type':'application/json;charset=UTF-8'
		},
		data:{
			firstName:'ali',lastName:'Kiani'
		}}
		axios(option).then(response=>{console.log(response.data)}).catch(err=>console.log(err))

}

const url="https://jsonplaceholder.ir/users";
const option={
	method:"GET",
	headers:{
		'Accept':'application/json',
		'Contact-Type':'application/json;charset=utf-8'
	}}

fetch(url,option).then(response=>response.json).then(data=>{console.log(data)}).catch(err=>console.log(err))