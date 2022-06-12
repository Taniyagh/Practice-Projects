import React, { Component } from 'react';
import { LoginContext } from '../Context/loginContext';
import { ThemeContext } from '../Context/ThemeContext';
class NavBar extends Component {
    static contextType=ThemeContext
    render() {
        const {isLight, dark, Light} = this.context;
        const Theme=isLight?Light:dark;
        const {login,changeLogin}=LoginContext
        return (
            <nav style={{background:Theme.item, color:Theme.text}}>
                <div onClick={changeLogin}>
                    {login ? 'شما وارد سایت شده اید' : 'لطفا وارد سایت شوید'}
                </div> 
                <h1>
                    <ul>
                        <li>خانه</li>
                        <li>درباره ما</li>
                        <li>تماس با ما</li>
                    </ul>
                </h1>
            </nav>
        );
    }
}
 
export default NavBar;