// JavaScript source code
const number=[1,2,3,4,12,5]
const result=number.reduce((accumlator,value)=>{
	if(accumlator>value)
	{
		return accumlator;
	}else{
		return value;
	}
},-Infinity)
console.log(result)