/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Microsoft Corporation. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
'use strict';
import * as worker from 'monaco-editor/esm/vs/editor/editor.worker.js';
import { HTMLWorker } from 'monaco-editor/esm/vs/language/html/htmlWorker.js';
self.onmessage = function () {
    // ignore the first message
    worker.initialize(function (ctx, createData) {
        return new HTMLWorker(ctx, createData);
    });
};
