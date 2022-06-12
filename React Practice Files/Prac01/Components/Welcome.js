import React, {Component} from 'react';
class Welcome extends Component{
    state={
        message: 'به وب سایت ما خوش آمدید. لطفاْ وارد حساب کاربری شوید.'
    }

    login = () =>{
        this.setState({message: "از ورود شما متشکریم"})
    }

    render(){
        return (
            <>
                <h2>
                {/* Welcome to our website! */}            
                {/* {this.props.children} */}
                {this.props.user}, 
                {this.state.message}
                </h2>
                <button onClick={this.login}>ورود</button>
            </>   
        )
    }
}
export default Welcome;