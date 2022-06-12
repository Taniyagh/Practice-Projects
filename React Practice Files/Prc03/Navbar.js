import React,{useContext} from 'react';
import { BookContext } from '../Context/BookContext';

const Navbar = () => {
    const{books}=useContext(BookContext)

    return ( 
        <div className='navbar'>
            <h1>لیست کتاب های من</h1>
            <p> اکنون شما
                {books.length}
                 کتاب در کتابخانه دارید.
            </p>
        </div>
     );
}
 
export default Navbar;