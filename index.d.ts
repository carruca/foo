// Type definations for passport-42
// Project: [ THE PROJECT NAME ]
// Definations by: tsierra- <https://github.com/carruca>

/// <reference types="passport" />

import { Strategy as Oauth2Strategy } from 'passport-oauth2';

declare function Strategy(options: any, verify: any): void;
declare class Strategy extends Oauth2Strategy {
	constructor(
		options: any,
		verify: any
	);

	name: string;
	_profileURL: any;
	_profile_Fields: any;
	userProfile(
		accessToken: any,
		done: any
	): void;
}
