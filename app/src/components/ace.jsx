import React from 'react';

// Import Brace and the AceEditor Component
//import brace from 'brace';
import AceEditor from 'react-ace';

// Import a Mode (language)
import 'brace/mode/ocaml';

// Import a Theme (okadia, github, xcode etc)
import 'brace/theme/monokai';

import 'brace/ext/language_tools';
import 'brace/ext/searchbox';

class AceComponent extends React.Component {
    componentWillMount() {
	this.props.glEventHub.on( this.props.file, this.setValue, this );
	this.props.glContainer.on( 'resize', function(){
	    window.dispatchEvent(new Event('resize'));
	});
    }

    componentWillUnmount() {
	this.props.glEventHub.off( this.props.file, this.setValue, this );
    }
    
    valChanged(newValue) {
	this.props.glEventHub.emit( this.props.file, newValue);
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
            name={ this.props.file}
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

export default AceComponent