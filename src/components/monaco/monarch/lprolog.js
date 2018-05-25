// Create your own language definition here
// You can safely look at other samples without losing modifications.
// Modifications are not saved on browser refresh/close though -- copy often!
module.exports = {
  // Set defaultToken to invalid to see what you do not tokenize yet
  defaultToken: 'invalid',

  keywords: [
    'accum_sig', 'accumulate', 'closed', 'end', 'exportdef',
    'import', 'infix', 'infixl', 'infixr', 'kind', 'local',
    'localkind', 'module', 'postfix', 'postfixl', 'prefix',
    'prefixr', 'sig', 'type', 'typeabbrev', 'use_sig', 'useonly'
  ],

  moreKeywords: [
    'pi', 'sigma', ',', ';', '&', '=', '+', '-', '*', '/', '::',
    'nil', '~', '<', '>', '=<', '>='
  ],

  typeKeywords: [
    'int', 'real', 'string', 'in_stream', 'out_stream', 'prop', 'list'
  ],

  pervasives: [
    'sqrt', 'sin', 'cos', 'arctan', 'ln', 'floor', 'ceil',
    'truncate', '^', 'size', 'chr', 'string_of_int', 'substring',
    'int_to_string', 'real_to_string', 'std_in', 'std_out',
    'std_err', 'nil', '::', '<', '>', '=<', '=>'
  ],

  ioPreds: [
    'is', 'time', 'getenv', 'open_in', 'open_out', 'open_append',
    'open_string', 'close_in', 'close_out', 'term_to_string',
    'string_to_term', 'input', 'output', 'input_line', 'lookahead',
    'eof', 'flush', 'print', 'read', 'printterm', 'readterm',
    'open_socket', 'system'
  ],

  // we include these common regular expressions
  symbols: /[\.:\->]+/,

  // C# style strings
  escapes: /\\(?:[abfnrtv\\"]|x[0-9A-Fa-f]{1,4}|u[0-9A-Fa-f]{4}|U[0-9A-Fa-f]{8})/,

  // The main tokenizer for our languages
  tokenizer: {
    root: [
      // identifiers and keywords
      [/[a-z_$][\w+\-*\/^<>=`?@#$&!_~']*/, {
        cases: {
          '@typeKeywords': 'keyword',
          '@keywords': 'keyword',
          '@ioPreds': 'keyword',
          '@default': 'identifier'
        }
      }],
      [/[A-Z][\w\$]*/, 'variable'],

      // whitespace
      { include: '@whitespace' },

      // delimiters and operators
      [/[{}()\[\]]/, '@brackets'],
      [/[<>](?!@symbols)/, '@brackets'],
      [/@symbols/, {
        cases: {
          '@pervasives': 'operator',
          '@default': ''
        }
      }],

      // @ annotations.
      // As an example, we emit a debugging log message on these tokens.
      // Note: message are supressed during the first load -- change some lines to see them.
      //[/@\s*[a-zA-Z_\$][\w\$]*/, { token: 'annotation', log: 'annotation token: $0' }],

      // numbers
      [/\d*\.\d+([eE][\-+]?\d+)?/, 'number.float'],
      [/\d+/, 'number'],

      // delimiter: after number because of .\d floats
      [/[;,.]/, 'delimiter'],

      // strings
      [/"([^"\\]|\\.)*$/, 'string.invalid'],  // non-teminated string
      [/"/, { token: 'string.quote', bracket: '@open', next: '@string' }],
    ],

    string: [
      [/[^\\"]+/, 'string'],
      [/@escapes/, 'string.escape'],
      [/\\./, 'string.escape.invalid'],
      [/"/, { token: 'string.quote', bracket: '@close', next: '@pop' }]
    ],

    whitespace: [
      [/[ \t\r\n]+/, 'white'],
      [/%.*$/, 'comment'],
    ],
  },
};