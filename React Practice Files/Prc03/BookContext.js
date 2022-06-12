import React,{createContext,useState, useEffect,useReducer} from 'react';
import { BookReducer } from '../Reducer/BookReducers';


export const BookContext=createContext();
const BookContextProvider = (props) => {
    
    const [books, dispatch]=useReducer(BookReducer,[],()=>{
        const data=localStorage.getItem('books');
        return data ? JSON.parse(data):[]
    })
    
    // const [books,setBook]=useState([
    //     {title:'صد سال تنهایی', author:'گابریل گارسیا مارکز', id:1},
    //     {title:'کیمیاگر', author:'پایولوکویلو', id:2},
    // ])

    // const removeBook=(id)=>{
    //     setBook(books.filter(book=>book.id !== id))
    // }

    // const addBook= (title, author)=>{
    //     setBook([...books, {title,author,id:uuid()}])
    // }
    useEffect(()=>{
        localStorage.setItem('books',JSON.stringify(books))
    },[books])
    return ( 
        <BookContext.Provider   value={{books, dispatch}}>
            {props.children}
        </BookContext.Provider>
     );
}
 
export default BookContextProvider;