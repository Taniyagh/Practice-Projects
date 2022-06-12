import React,{useContext} from 'react';
import { BookContext } from '../Context/BookContext';
import BookDetails from './BookDetails';


const BookList = () => {
    const {books}=useContext(BookContext)
    return books.length?( 
        <div className='book-list'>
            <ul>
                {books.map(book=>{
                    return (<BookDetails key={book.id} book={book}></BookDetails>)
                })}
            </ul>
        </div>
     ):(
        <div>
            هیچ کتابی یافت نشد.
        </div>
     );
}
 
export default BookList;