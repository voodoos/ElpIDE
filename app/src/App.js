import React, { Component } from 'react';
import ReactDOM from 'react-dom';
import GoldenLayout from 'golden-layout';
import CreateReactClass from 'create-react-class';
import logo from './logo.svg';
import './App.css';

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
            component: 'testComponent',
            props: { label: 'A' }
        },{
            type: 'column',
            content:[{
                type:'react-component',
                component: 'testComponent',
                props: { label: 'B' }
            },{
                type:'react-component',
                component: 'testComponent',
                props: { label: 'C' }
            }]
        }]
    }]
});

var TestComponent = CreateReactClass({
    render: function() {
        return (<h1>{this.props.label}</h1>)
    }
});

myLayout.registerComponent( 'testComponent', TestComponent );

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
