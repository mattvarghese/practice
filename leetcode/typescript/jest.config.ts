import type { Config } from 'jest';

const config: Config = {
    preset: 'ts-jest',
    testEnvironment: 'node',
    testMatch: ['**/*_test.ts'], // Keeps your suffix-aligned scheme intact
};

export default config;
