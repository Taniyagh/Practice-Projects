import React, { Component } from 'react';
import '../MyClass.css';

class StyleSheet extends Component {
    state = {  } 
    render() {
        let className=this.props.primary ? "primary" : '' 
        return (
            <div>
                <h1 className={`${className} font-x`}>
                    Style Sheet
                </h1>
            </div>
        );
    }
}
 
export default StyleSheet;