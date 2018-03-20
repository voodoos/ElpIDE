import React, { Component } from 'react';
import ReactDOM from 'react-dom';
import GoldenLayout from 'golden-layout';
import logo from './logo.svg';
import './App.css';

// Import Brace and the AceEditor Component
//import brace from 'brace';
import AceEditor from 'react-ace';

// Import a Mode (language)
import 'brace/mode/ocaml';

// Import a Theme (okadia, github, xcode etc)
import 'brace/theme/monokai';

import 'brace/ext/language_tools';
import 'brace/ext/searchbox';

import 'golden-layout/dist/goldenlayout.min.js'
import 'golden-layout/src/css/goldenlayout-base.css'
import 'golden-layout/src/css/goldenlayout-dark-theme.css'

window.React = React
window.ReactDOM = ReactDOM

var myLayout = new GoldenLayout({
    content: [{
        type: 'row',
        content:[{
            type:'react-component',
            component: 'aceComponent',
            props: { label: 'A' }
        },{
            type: 'column',
            content:[{
                type:'react-component',
                component: 'aceComponent',
                props: { label: 'B' }
            },{
                type:'react-component',
                component: 'aceComponent',
                props: { label: 'C' }
            }]
        }]
    }]
});


class AceComponent extends React.Component {
    componentWillMount() {
	this.props.glEventHub.on( 'text_changed', this.setValue, this );
	this.props.glContainer.on( 'resize', function(){
	    window.dispatchEvent(new Event('resize'));
	});
    }

    componentWillUnmount() {
	this.props.glEventHub.off( 'text_changed', this.setValue, this );
    }
    
    valChanged(newValue) {
	this.props.glEventHub.emit('text_changed', newValue);
    }
    
    setValue(newValue) {
	this.setState({ value: newValue });
    }
    
    render() {
	var val = "tata";
	if( this.state ) {
	    val = this.state.value;
	}
	
	return (
                <AceEditor
            mode="ocaml"
            theme="monokai"
            onChange={(n) => this.valChanged(n)}
            name={this.props.label}
	    width="100%"
	    height="100%"
	    value={ val }
	    setOptions={{
		enableBasicAutocompletion: true,
		enableLiveAutocompletion: true,
		enableSnippets: false,
		showLineNumbers: true,
		tabSize: 4,
	    }}
                />
        );
    }
}

myLayout.registerComponent( 'aceComponent', AceComponent );

myLayout.init();

class App extends Component {
  render() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <h1 className="App-title">Welcome to React</h1>
        </header>
        <p className="App-intro">
          Pouet
        </p>
      </div>
    );
  }
}

export default App;

