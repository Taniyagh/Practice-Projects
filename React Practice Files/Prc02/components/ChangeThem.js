import React, { Component } from 'react';
import { ThemeContext } from '../Context/ThemeContext';
class ChangeTheme extends Component {
    static contextType=ThemeContext;
    render() { 
        const {ChangeTheme}=this.context;
        
        return (
            <button onClick={ChangeTheme}>
                Change Theme
            </button>
        );
    }
}
 
export default ChangeTheme;