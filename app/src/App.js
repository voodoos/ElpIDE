import React, { Component } from 'react';
import ReactDOM from 'react-dom';
import GoldenLayout from 'golden-layout';

import './App.css';

import AceComponent from './components/ace.jsx'
import MenuComponent from './components/menu.jsx'


import 'golden-layout/dist/goldenlayout.min.js'
import 'golden-layout/src/css/goldenlayout-base.css'
import 'golden-layout/src/css/goldenlayout-dark-theme.css'

import 'semantic-ui-css/semantic.min.css'
import './ui.css'

window.React = React
window.ReactDOM = ReactDOM


var myLayout = new GoldenLayout({
    content: [{
        type: 'row',
        content:[{
            type:'react-component',
            component: 'aceComponent',
	    title: 'FileA',
            props: { file: 'FileA' }
        },{
            type: 'column',
            content:[{
                type:'react-component',
                component: 'aceComponent',
		title: 'FileA',
                props: { file: 'FileA' }
            },{
                type:'react-component',
                component: 'aceComponent',
		title: 'FileB',
                props: { file: 'FileB' }
            }]
        }]
    }]
}, '#gl_container');


myLayout.registerComponent( 'aceComponent', AceComponent );

myLayout.init();
myLayout.on('initialised',
	    () => window.addEventListener('resize',
					  () => myLayout.updateSize()
					 )
	   );


class App extends Component {
    render() {
	return (
		<div id="App" className="App">
		<div id="navbar">
		  <MenuComponent />
		</div>
		<div id="gl_container"></div>
		</div>);
    }
}

export default App
