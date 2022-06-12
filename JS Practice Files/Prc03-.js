// JavaScript source code
let data=[];
window.onload=function(){
	axios({
        url:'https://jsonplaceholder.ir/photos',
        method:'get'
    }).then(res=>{    
        data = res.data;
        showPhoto()      
    })
	const search_input=document.getElementById('search');
	search_input.addEventListener('input',e=>{
	search_term=e.target.value;
	filterBarHandler();
	})
	}

const showPhoto=()=>{
	const container=document.querySelector('.mediaSection');
	data.map((item)=>{
		const newMedia=document.createElement('div');
		const photo=document.createElement('img');
		const title=document.createElement('span');
		photo.setAttribute('src',item.url);
		title.innerHTML=item.title;

		newMedia.appendChild(photo);
		newMedia.appendChild(title);

		newMedia.classList='media';

		container.appendChild(newMedia);
	})
	deleteItem();
}


const deleteItem=()=>{
	const PhotoList=document.querySelectorAll('.mediaSection div');
	for (item of PhotoList)
	{
		item.addEventListener('click',function(){
			this.remove();
		})
	}
}

const filterBarHandler=()=>{
	const container=document.querySelector('.mediaSection');
	container.innerHTML='';
	data.filter(item=>item.title.toLowerCase().includes(search_term.toLowerCase())).forEach(item=>{
		addToDOM(item)
	})
}

const addToDOM = (item)=>{
		const loading=document.querySelector('.loading')
		const container=document.querySelector('.mediaSection');
		const newMedia=document.createElement('div');
		const photo=document.createElement('img');
		const title=document.createElement('span');
		photo.setAttribute('src',item.url);
		title.innerHTML=item.title;

		newMedia.appendChild(photo);
		newMedia.appendChild(title);

		newMedia.classList='media';

		container.appendChild(newMedia);
		loading.classList.remove('show');
}

window.addEventListener('scroll',()=>{
	const{scrollTop,scrollHeight,clientHeight}=document.documentElement
	if(clientHeight+scrollTop>=scrollHeight-5)
	{
		showLoading()
	}
})

const showLoading=()=>{
	const loading=document.querySelector('.loading')
	loading.classList.add('show')
	setTimeout(getPhoto(),1000)
}

const getPhoto=()=>{
	axios({
        url:`https://jsonplaceholder.ir/photos/${Math.floor(Math.random()*100+1)}`,
        method:'get'
    }).then(res=>{    
        addToDOM(res.data) 
    })
}