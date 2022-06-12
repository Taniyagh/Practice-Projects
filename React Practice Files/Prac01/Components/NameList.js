import React from 'react';
import Person from './Person.js'
function NameList(){
    const persons=[
        {
            id:1,
            name:'Ali',
            age:22,
        },
        {
            id:2,
            name:'Mohammad',
            age:32
        },
        {
            id:3,
            name:'Mehran',
            age:42
        }
    ]
    // const names=['Ali','Mohammad','Reza','Mehdi'];
    const PersonList=persons.map(person=><Person person={person} key={person.id}/>)
    return (
        <div>
            {/* {names.map(name=><h2>{name}</h2>)} */}
            {PersonList}
        </div>
    )
}

export default NameList;